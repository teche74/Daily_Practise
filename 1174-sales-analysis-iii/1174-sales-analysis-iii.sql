select p.product_id,p.product_name from Product p join Sales s 
on p.product_id = s.product_id group by s.product_id having
max(s.sale_date) <  DATE '2019-04-01' and 
min(s.sale_date) > DATE '2018-12-31';