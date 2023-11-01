from cs50 import get_int


def main():
    # Prompt the user for a credit card number
    while True:
        number = get_int("Number: ")
        if number > 0:
            break

    sum_for_test = calculate(number)
    card = str(number)
    card_length = len(card)
    first_digit = int(card[0])
    second_digit = int(card[1])
    # print(f"{sum_for_test}")
    # print(f"{card_length}")
    # print(f"{first_digit}")
    # print(f"{second_digit}")

    # Check the validity of the card number
    if sum_for_test % 10 == 0:
        if card_length == 15 and first_digit == 3 and (second_digit == 4 or second_digit == 7):
            print("AMEX")
        elif card_length == 16 and first_digit == 5 and (second_digit >= 1 and second_digit <= 5):
            print("MASTERCARD")
        elif (card_length == 13 or card_length == 16) and first_digit == 4:
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


def calculate(number):
    copy = number
    even_sum = 0
    odd_sum = 0
    while copy > 0:
        even = copy % 100 // 10
        even *= 2
        while even >= 10:
            even_sum += even % 10
            even //= 10
        even_sum += even
        odd_sum += copy % 100 % 10
        copy //= 100
    sum_for_test = even_sum + odd_sum
    return sum_for_test


main()