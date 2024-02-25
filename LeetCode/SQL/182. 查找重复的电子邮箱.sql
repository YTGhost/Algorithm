# Write your MySQL query statement below
select Email from Person group by email having COUNT(Email) > 1;