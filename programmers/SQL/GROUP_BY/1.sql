-- 코드를 입력하세요
SELECT ANIMAL_TYPE, COUNT(ANIMAL_ID)
FROM ANIMAL_INS
GROUP BY ANIMAL_TYPE
HAVING ANIMAL_TYPE = "Cat" OR ANIMAL_TYPE = "Dog"
ORDER BY ANIMAL_TYPE;

/* 조건문 쓸 때 ==이 아니라 = */