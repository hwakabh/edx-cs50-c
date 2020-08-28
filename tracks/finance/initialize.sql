-- Run `cat ./initialize.sql |sqlite3 finance.db` for initializing
DROP TABLE stocks;
DROP TABLE history;

-- Truncate user data
DELETE FROM users;
