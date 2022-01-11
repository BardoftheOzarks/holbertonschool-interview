#!/usr/bin/python3
'''Counts use of given words in a given subreddit's hot articles list'''
import requests


def count_words(subreddit, word_list, after=None, counts={}):
    '''prints counts of keywords used in a subreddit's hot articles list'''
    if after is not None:
        url = 'https://api.reddit.com/r/{}/hot.json?after={}'.format(subreddit,
                                                                     after)
    else:
        url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
        lower_list = (map(lambda word: word.lower(), word_list))
        word_list = list(lower_list)
        for word in word_list:
            if word not in counts.keys():
                counts[word] = 0
    headers = {'User-Agent': 'user'}
    r = requests.get(url, headers=headers, allow_redirects=False)
    try:
        data = r.json().get('data')
    except:
        return
    children = data.get('children')
    for child in children:
        title = child.get('data').get('title').lower()
        title = title.split(' ')
        for word in title:
            if word in word_list:
                counts[word] += 1
    after = data.get('after')
    if after is not None:
        return count_words(subreddit, word_list, after, counts)
    else:
        sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
        for word in sorted_counts:
            if word[1] > 0:
                print('{}: {}'.format(word[0], word[1]))
