SELECT * FROM shows LIMIT 10;
SELECT COUNT(*) FROM shows;
SELECT COUNT(*) FROM shows WHERE startYear = 2019;
SELECT * FROM shows WHERE title = "The Office";
SELECT * FROM shows WHERE primaryTitle = "The Office";

SELECT * FROM shows LIMIT 100;

-- Under estimation since show includes multiple genres are excluded
SELECT * FROM shows WHERE genres = "Comedy" AND startYear = 2019;
SELECT COUNT(*) FROM shows WHERE genres = "Comedy" AND startYear = 2019;
SELECT COUNT(*) FROM shows WHERE genres = "%Comedy%" AND startYear = 2019;
