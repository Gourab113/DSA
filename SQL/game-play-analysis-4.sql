   
  -- 550. Game Play Analysis IV 


select
    round((select count(a.player_id)
    from Activity a
    join Activity c
    on a.player_id = c.player_id and
    datediff(c.event_date, a.event_date) = 1
    where (a.player_id,a.event_date) in 
    (
        select player_id, min(event_date)
        from Activity
        group by player_id
    ))/
    (
        select count(distinct player_id)
        from Activity
    ),2) as 'fraction';

