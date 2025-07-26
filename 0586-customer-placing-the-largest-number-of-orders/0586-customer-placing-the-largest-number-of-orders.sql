with modify_table as (
    select customer_number , count(*) as total_buy from Orders group by customer_number
)

select customer_number from modify_table where total_buy = (select max(total_buy) from modify_table)