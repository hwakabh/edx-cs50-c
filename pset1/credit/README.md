# Credit

- Implementation of `Luhn Algorithm`

- Credit Card number specifications of each company
  - AMEX :
    - 15 digits
    - starts with 34 or 37
  - MasterCard :
    - 16 digits
    - starts with 51, 52, 53, 54, 55
  - Visa :
    - 13 or 16 digits
    - starts with 4

- Checksum Calculations
  - Starting with the number’s second-to-last digit, multiply each of number by 2, and get the subtotal of them
    - Consider the case of `378282246310005`, you should calculate like:
      - 0*2 + 0*2 + 3*2 + 4*2 + 2*2 + 2*2 + 7*2
  - Case if the number multiply by 2 is bigger than 10, we have to split each digit, and caluculate like:
    - 0 + 0 + 6 + 8 + 4 + 4 + 1 + 4 = 27
      - The results of 7*2 is 14, which is bigger than 10, so we must split 14 to 1+4
  - Counts up the reminders which we do not calculate yet
    - 3 + 8 + 8 + 2 + 6 + 1 + 0 + 5 = 33
  - Get checksum of them and check MOD-10
    - 27 + 33 = 60
    - 60 mod(10) = 0
  - If mod(10) of checksum is 0, the card is valid, or if not, invalid.

- Example Card numbers for testings and development
  - https://developer.paypal.com/docs/classic/payflow/payflow-pro/payflow-pro-testing/#credit-card-numbers-for-testing

  - AMEX
    - Valid numbers
      - 378282246310005 / 371449635398431 / 378734493671000
  - MASTER
    - Valid numbers
      - 2221000000000009 / 2223000048400011 / 2223016768739313
    - Invalid numbers
      - 5555555555554444 / 5105105105105100
  - VISA
    - Valid numbers
      - 4111111111111111 / 4012888888881881 / 4222222222222
  