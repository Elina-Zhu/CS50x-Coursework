SELECT AVG(energy)
From songs
WHERE artist_id = (
    SELECT id
    FROM artists
    WHERE name = 'Drake'
);