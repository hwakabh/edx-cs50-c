-- Set modes: csv, line
.mode csv
-- Load source data from .csv file to table
.import "./srcdata/costs.csv" costs
-- Show all tables
.tables
.header on

-- Run some SQL commands
SELECT * FROM costs;
SELECT hlpi_name FROM costs;
SELECT hlpi_name FROM costs ORDER BY hlpi_name;
SELECT hlpi_name, COUNT(hlpi_name) FROM costs GROUP BY hlpi_name;
SELECT hlpi_name, COUNT(hlpi_name) FROM costs GROUP BY hlpi_name LIMIT 5;
SELECT hlpi_name, COUNT(hlpi_name) AS n FROM costs GROUP BY hlpi_name LIMIT 5;
SELECT hlpi_name, COUNT(hlpi_name) AS n FROM costs GROUP BY hlpi_name ORDER BY n DESC LIMIT 2;
SELECT DISTINCT(hlpi_name) FROM costs;
SELECT hlpi_name FROM costs WHERE hlpi_name = 'Maori';
SELECT COUNT(hlpi_name) FROM costs WHERE hlpi_name LIKE "%quintile%"

-- Data cleanup example
UPDATE costs SET hlpi_name = 'Quintile N' WHERE hlpi_name LIKE "%quintile%";
DELETE FROM costs WHERE hlpi_name = 'Maori';
