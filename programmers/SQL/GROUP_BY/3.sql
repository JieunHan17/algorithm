-- 코드를 입력하세요
SELECT HOUR(DATETIME), COUNT(ANIMAL_ID)
FROM ANIMAL_OUTS
WHERE 9 <= HOUR(DATETIME) AND HOUR(DATETIME) <= 19
GROUP BY HOUR(DATETIME)
ORDER BY HOUR(DATETIME);