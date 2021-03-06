-- 코드를 입력하세요
SELECT O.ANIMAL_ID, O.NAME
FROM ANIMAL_INS I JOIN ANIMAL_OUTS O
ON I.ANIMAL_ID = O.ANIMAL_ID
ORDER BY TIMESTAMPDIFF(DAY, O.DATETIME, I.DATETIME)
LIMIT 2;

-- 코드를 입력하세요
SELECT O.ANIMAL_ID, O.NAME, O.DATETIME - I.DATETIME
FROM ANIMAL_INS I JOIN ANIMAL_OUTS O
ON I.ANIMAL_ID = O.ANIMAL_ID
ORDER BY O.DATETIME - I.DATETIME DESC
LIMIT 2;