-- 1. ვკითხულობთ ინტერვიუებს, რომ გავიგოთ ქურდობის დეტალები
SELECT transcript FROM interviews WHERE month = 7 AND day = 28 AND year = 2025;

-- 2. ვეძებთ საცხობის კამერის ჩანაწერებს (ქურდობა მოხდა ჰამფრის ქუჩაზე)
SELECT * FROM bakery_security_logs WHERE month = 7 AND day = 28 AND year = 2025 AND hour = 10 AND minute BETWEEN 15 AND 25;

-- 3. ვეძებთ ბანკომატის ტრანზაქციებს ლეგეტის ქუჩაზე იმავე დღეს
SELECT * FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2025 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- 4. ვეძებთ მოკლე სატელეფონო ზარებს (60 წამზე ნაკლები) ქურდობის დღეს
SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2025 AND duration < 60;

-- 5. ვპოულობთ ფრენებს Fiftyville-დან 29 ივლისს (ქურდობის მომდევნო დღეს)
SELECT * FROM flights WHERE month = 7 AND day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') ORDER BY hour ASC;

-- 6. ვპოულობთ მგზავრებს კონკრეტული ფრენისთვის (დავუშვათ ფრენის ID არის 36)
SELECT * FROM passengers WHERE flight_id = 36;

-- 7. ვაერთიანებთ ინფორმაციას: ვინ იყო საცხობთან, ბანკომატთან, ვინ დარეკა და ვინ გაფრინდა
-- (აქ ვპოულობთ ქურდის სახელს)
SELECT name FROM people
WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street'))
AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25)
AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36)
AND phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60);

-- 8. ვპოულობთ თანამზრახველს (ვინც მიიღო ქურდის ზარი)
SELECT name
FROM people
WHERE phone_number = '(375) 555-8161';

-- 9. ვპოულობთ გაქცევის ქალაქს (ფრენის დანიშნულების ადგილი)
SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE id = 36);
