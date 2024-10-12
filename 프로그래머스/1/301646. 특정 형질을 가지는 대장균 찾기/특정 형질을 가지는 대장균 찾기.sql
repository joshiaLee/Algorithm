SELECT COUNT(*) AS COUNT
FROM ECOLI_DATA
WHERE (GENOTYPE & 2) = 0  -- 2번 형질이 없는 대장균
AND ((GENOTYPE & 1) != 0  -- 1번 형질을 보유
     OR (GENOTYPE & 4) != 0);  -- 또는 3번 형질을 보유