# Write your MySQL query statement below
with t1 as (select product_id,
case 
    when change_date<='2019-08-16' or (change_date>'2019-08-16' and (select count(*) from products where change_date<='2019-08-16' and A.product_id=product_id
                                           group by product_id )>=1) 
                                           
                                 then (select max(change_date) from products where 
                                           change_date<='2019-08-16' and 
                                           A.product_id=product_id
                                           group by product_id )
    
                                
    else max(change_date)
    end as dates

from products A
group by product_id
)
select B.product_id,
case
when change_date <='2019-08-16' then new_price
else 10
end as price
from products as B
join t1 on B.product_id=t1.product_id and B.change_date=t1.dates

