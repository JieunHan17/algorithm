-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME, SEX_UPON_INTAKE
FROM ANIMAL_INS I
WHERE I.NAME IN ('Lucy', 'Ella', 'Pickle', 'Sabrina', 'Mitty')
ORDER BY I.ANIMAL_ID;