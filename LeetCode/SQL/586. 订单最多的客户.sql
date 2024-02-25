# Write your MySQL query statement below
select customer_number
from Orders
group by customer_number
order by COUNT(*) desc
limit 1

# 进阶： 如果有多位顾客订单数并列最多，你能找到他们所有的 customer_number 吗？
# Write your MySQL query statement below
select customer_number
from Orders
group by customer_number
having COUNT(*) = (
    select COUNT(customer_number) as 'cnt'
    from Orders
    group by customer_number
    order by cnt desc
    limit 1
)
