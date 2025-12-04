#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];

if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(filmUrl, function (error, response, body) {
  if (error) {
    console.error('Error fetching film data:', error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error('Film not found');
    return;
  }

  const filmData = JSON.parse(body);
  const characterUrls = filmData.characters;
  let completed = 0;

  characterUrls.forEach((characterUrl, index) => {
    request(characterUrl, function (error, response, body) {
      if (error) {
        console.error('Error fetching character:', error);
        return;
      }

      const characterData = JSON.parse(body);
      characterUrls[index] = characterData.name;
      completed++;

      if (completed === characterUrls.length) {
        characterUrls.forEach(name => {
          console.log(name);
        });
      }
    });
  });
});
