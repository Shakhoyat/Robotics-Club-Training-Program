import cv2
import mediapipe as mp
import math
import serial

ser = serial.Serial('COM7', 9600)  # Serial port khule dichhi, port name change korte paro
cam = cv2.VideoCapture(0)          # Camera open korlam
hands = mp.solutions.hands.Hands() # Mediapipe diye hand tracking setup korlam

while True:
    _, frame = cam.read()          # Camera theke frame nilam
    frame = cv2.flip(frame, 1)     # Frame ta ulta korlam (mirror effect)
    rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB) # BGR theke RGB te convert korlam
    result = hands.process(rgb)    # Hand landmarks ber korlam

    if result.multi_hand_landmarks:
        hand = result.multi_hand_landmarks[0] # Prothom hand ta nilam
        h, w, _ = frame.shape                 # Frame er height, width nilam
        thumb = hand.landmark[4]              # Thumb tip er landmark nilam
        index = hand.landmark[8]              # Index finger tip er landmark nilam
        x1, y1 = int(thumb.x * w), int(thumb.y * h) # Thumb tip er pixel position
        x2, y2 = int(index.x * w), int(index.y * h) # Index tip er pixel position

        cv2.circle(frame, (x1, y1), 5, (0, 255, 0), -1) # Thumb tip e circle draw korlam
        cv2.circle(frame, (x2, y2), 5, (0, 255, 0), -1) # Index tip e circle draw korlam

        dist = math.hypot(x2 - x1, y2 - y1) # Thumb ar index er majhe distance ber korlam
        state = 'a' if dist < 50 else 'b'   # Distance kom hole 'a', na hole 'b' set korlam
        print(state)                        # State print korlam
        ser.write((state + '\r').encode())  # State serial e pathailam

    cv2.imshow('Hand', frame)               # Frame show korlam
    if cv2.waitKey(1) == ord('q'):          # 'q' chaple loop theke ber hoye jabo
        break

ser.close()                                 # Serial port bondho korlam
cam.release()                               # Camera release korlam
cv2.destroyAllWindows()                     # Sob window bondho korlam