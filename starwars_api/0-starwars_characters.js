#!/usr/bin/node

const request = require('request');

function makeRequest (url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error) {
        reject(error);
      }
      resolve(body);
    });
  });
}

const args = process.argv.slice(2);
if (args.length !== 1) {
  console.log('Usage: ./0-starwars_characters.js <film number>');
  process.exit(1);
}
const url = 'https://swapi-api.hbtn.io/api/films/' + args[0];

makeRequest(url).then((body) => {
  const promises = [];
  const charactersURL = JSON.parse(body).characters;
  for (let i = 0; i < charactersURL.length; i++) {
    promises.push(makeRequest(charactersURL[i]));
  }
  return Promise.all(promises)
    .then((values) =>
      console.log(values.map((value) => JSON.parse(value).name).join('\n'))
    );
});
