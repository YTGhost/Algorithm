# Write your MySQL query statement below
select
round(
    ifnull(
        (select COUNT(*) from (select distinct requester_id, accepter_id from RequestAccepted) as a)
        /
        (select COUNT(*) from (select distinct sender_id, send_to_id from FriendRequest) as b)
        , 0)
, 2)
as accept_rate