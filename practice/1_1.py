def split_vowels_consonants(s):
    vowels = "aeiouAEIOU"
    vowel_chars = ""
    consonant_chars = ""

    for char in s:
        if char.isalpha():
            if char in vowels:
                vowel_chars += char
            else:
                consonant_chars += char

    return (vowel_chars, len(vowel_chars), consonant_chars)


if __name__ == "__main__":
    result = split_vowels_consonants("abcdefg")
    print(result)