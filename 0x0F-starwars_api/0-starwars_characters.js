#!/usr/bin/node
const request = require('request');
request('https://swapi-api.hbtn.io/api/films/' + process.argv[2],
  (err, response, body) => {
    if (err) {
      console.log(err);
    } else {
      const characters = JSON.parse(body).characters;
      const charactersSorted = {};
      for (const link in characters) {
        request(characters[link], (err, response, body) => {
          if (err) {
            console.log(err);
          } else {
            const name = JSON.parse(body).name;
            charactersSorted[link] = name;
          }
          if (Object.values(charactersSorted).length === characters.length) {
            for (let i = 0; i < characters.length; i++) {
              console.log(charactersSorted[i]);
            }
          }
        });
      }
    }
  });
