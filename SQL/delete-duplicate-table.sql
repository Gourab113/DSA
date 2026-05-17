-- Delete person table that have duplicate emails
-- same table not allow delete in subquery

delete p2
from Person p1, Person p2
where p1.email = p2.email and p1.id < p2.id;
