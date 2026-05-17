
-- can use subquery inside the select also
-- SQL 178, Rank Scores
-- potiti score er ekta rank dewa highest value rank 1
-- next value rank 2, same value have same rank

select s1.score, 
 (
    select count(distinct s2.score)
    from scores as s2
    where s2.score >= s1.score
 ) as 'rank'

from Scores as s1
order by s1.score desc;