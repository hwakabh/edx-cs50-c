-- Check 2 tables created
.schema

SELECT * FROM shows WHERE title = "The Office";

-- Read data with KEY
-- Note that name of KEY should be <tablename>_id
SELECT * FROM shows WHERE title = "The Office" AND year = 2005;
SELECT * FROM genres WHERE show_id = 386676;

SELECT * FROM shows WHERE title = "The Crown";
SELECT * FROM genres WHERE show_id = 4786824;

-- Nested query (conditions for shows: id and year)
SELECT * FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = "Comedy") AND year = 2019;
-- Playing with subqueries
SELECT * FROM people WHERE name = "Ellen DeGeneres";
SELECT * FROM stars WHERE person_id = 1122;
SELECT * FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Ellen DeGeneres")
SELECT show_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Ellen DeGeneres")
SELECT * FROM shows WHERE id IN (SELECT show_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Ellen DeGeneres"))

-- Reconsistitute records (with filterings)
SELECT * FROM shows JOIN genres ON shows.id = genres.show_id;
SELECT * FROM shows JOIN genres ON shows.id = genres.show_id WHERE title = "The Office" AND year = 2005;

SELECT title FROM
people JOIN stars ON people.id = stars.person_id
JOIN shows ON stars.show_id = shows.id
WHERE name = "Ellen DeGeneres";