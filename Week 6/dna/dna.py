import csv
import sys


def main():
    # 1. არგუმენტების შემოწმება
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # 2. მონაცემთა ბაზის წაკითხვა
    database = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)

    # 3. DNA მიმდევრობის წაკითხვა
    with open(sys.argv[2], "r") as file:
        dna_sequence = file.read().strip()

    # 4. STR-ების სია (ყველა სვეტი "name"-ის გარდა)
    # database[0] არის პირველი სტრიქონი, keys() გვაძლევს სვეტების სახელებს
    subsequences = list(database[0].keys())[1:]

    # 5. თითოეული STR-ისთვის მაქსიმალური განმეორების პოვნა
    dna_counts = {}
    for sub in subsequences:
        dna_counts[sub] = longest_match(dna_sequence, sub)

    # 6. მონაცემთა ბაზაში შედარება
    for person in database:
        match = True
        for sub in subsequences:
            # მნიშვნელოვანია: csv-დან წამოღებული რიცხვი გადავიყვანოთ int-ად
            if int(person[sub]) != dna_counts[sub]:
                match = False
                break

        if match:
            print(person["name"])
            return

    # თუ არაფერი დაემთხვა
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest_run = max(longest_run, count)
    return longest_run


main()
