SELECT people.name FROM people
WHERE people.id
IN (
    SELECT person_id FROM stars
    JOIN movies ON movies.id = stars.movie_id
    WHERE movie_id
    IN (
        -- Movies which Kevin Bacon starred
        SELECT movie_id FROM movies
        JOIN stars ON stars.movie_id = movies.id
        JOIN people ON people.id = stars.person_id
        WHERE people.id
        IN (
            -- Kevin Bacon, who born in 1958 and whose id = 102
            SELECT id FROM people
            WHERE people.name = "Kevin Bacon" AND people.birth = 1958
        )
    )
)
AND
-- Exclude Kevin Bacon himself
people.name != "Kevin Bacon";
