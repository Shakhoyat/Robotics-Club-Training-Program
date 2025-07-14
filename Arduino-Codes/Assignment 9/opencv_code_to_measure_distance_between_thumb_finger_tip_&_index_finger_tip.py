import cv2
import mediapipe as mp
import math

PIXEL_TO_CM = 0.026  # Example value, calibrate for your setup

cam = cv2.VideoCapture(0)  # camera open korlam
hands = mp.solutions.hands.Hands()  # hand detect korar jonno
while True:
    _, frame = cam.read()  # frame nilam
    frame = cv2.flip(frame, 1)  # frame ulta korlam
    results = hands.process(cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))  # hand landmark ber korlam

    if results.multi_hand_landmarks:  # jodi hand paowa jay
        for hand_landmarks in results.multi_hand_landmarks:
            thumb_tip = hand_landmarks.landmark[mp.solutions.hands.HandLandmark.THUMB_TIP]  # thumb tip ber korlam
            index_tip = hand_landmarks.landmark[mp.solutions.hands.HandLandmark.INDEX_FINGER_TIP]  # index tip ber korlam

            h, w, _ = frame.shape  # frame size nilam
            thumb_tip_px = (int(thumb_tip.x * w), int(thumb_tip.y * h))  # thumb tip pixel position
            index_tip_px = (int(index_tip.x * w), int(index_tip.y * h))  # index tip pixel position

            distance_px = math.sqrt((thumb_tip_px[0] - index_tip_px[0]) ** 2 + (thumb_tip_px[1] - index_tip_px[1]) ** 2)  # duita tip er distance ber korlam
            distance_cm = distance_px * PIXEL_TO_CM  # cm te convert korlam

            cv2.putText(frame, f'Distance: {distance_px:.2f} px / {distance_cm:.2f} cm', (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2)  # distance show korlam
            mp.solutions.drawing_utils.draw_landmarks(frame, hand_landmarks, mp.solutions.hands.HAND_CONNECTIONS)  # hand draw korlam

    cv2.imshow("Video Feed", frame)  # video dekhalam
    if cv2.waitKey(1) & 0xFF == ord('q'):  # q chaple ber hoye jabe
        break
