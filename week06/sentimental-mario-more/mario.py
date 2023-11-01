from cs50 import get_int

# Prompt the user for the half-pyramid's height
while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

# Generate the desired half-pyramids
counter = 1

for i in range(height):
    for x in range(height - counter):
        print(" ", end="")
    for y in range(counter):
        print("#", end="")
    print("  ", end="")
    for m in range(counter):
        print("#", end="")
    # for n in range(height - counter):
        # print(" ", end="")
    print("")
    counter += 1