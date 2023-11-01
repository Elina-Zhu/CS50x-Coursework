from cs50 import get_string


def main():
    text = get_string("Text: ")
    text_length = len(text)
    letters = count_letters(text, text_length)
    words = count_words(text, text_length)
    sentences = count_sentences(text, text_length)
    L = letters / words * 100
    S = sentences / words * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)
    # print(f"{letters} {words} {sentences}")

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def count_letters(text, text_length):
    letters = 0
    for i in range(text_length):
        if text[i].isalpha():
            letters += 1
    return letters


def count_words(text, text_length):
    words = 1
    for i in range(text_length):
        if text[i] == ' ':
            words += 1
    return words


def count_sentences(text, text_length):
    sentences = 0
    for i in range(text_length):
        if text[i] == '.' or text[i] == '?' or text[i] == '!':
            sentences += 1
    return sentences


main()