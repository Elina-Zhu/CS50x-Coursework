-- Get the crime scene report
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time –
-- each of their interview transcripts mentions the bakery.
SELECT description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

-- Get the interviews
SELECT id, name, transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';

-- Find the destination
SELECT * FROM flights
WHERE origin_airport_id IN (
    SELECT id FROM airports
    WHERE city = 'Fiftyville'
)
AND year = 2021 AND month = 7 AND day = 29
ORDER BY hour, minute
LIMIT 10;

SELECT * FROM airports
WHERE id = 4;

-- Figure out the thief
SELECT people.* FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE people.id IN (
    SELECT person_id FROM atm_transactions
    JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
    WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute <= 25
    AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
)
AND year = 2021 AND month = 7 AND day = 28 AND activity = 'exit'
AND passport_number IN (
    SELECT passport_number FROM passengers
    WHERE flight_id = 36
)
AND name IN (
    SELECT name
    FROM people
    JOIN phone_calls
    ON people.phone_number = phone_calls.caller
    WHERE phone_calls.year = 2021
    AND phone_calls.month = 7
    AND phone_calls.day = 28
    AND phone_calls.duration < 60
);

-- Find the accomplice
SELECT * FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE receiver IN (
    SELECT receiver FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 AND caller IN (
        SELECT phone_number FROM people
        WHERE name = 'Bruce'
    )
);