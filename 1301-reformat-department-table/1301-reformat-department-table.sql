select id,
Sum(if(month = 'Jan' , revenue , null)) as 'Jan_Revenue',
Sum(if(month = 'Feb' , revenue , null)) as 'Feb_Revenue',
Sum(if(month = 'Mar' , revenue , null)) as 'Mar_Revenue',
Sum(if(month = 'Apr' , revenue , null)) as 'Apr_Revenue',
Sum(if(month = 'May' , revenue , null)) as 'May_Revenue',
Sum(if(month = 'Jun' , revenue , null)) as 'Jun_Revenue',
Sum(if(month = 'Jul' , revenue , null)) as 'Jul_Revenue',
Sum(if(month = 'Aug' , revenue , null)) as 'Aug_Revenue',
Sum(if(month = 'Sep' , revenue , null)) as 'Sep_Revenue',
Sum(if(month = 'Oct' , revenue , null)) as 'Oct_Revenue',
Sum(if(month = 'Nov' , revenue , null)) as 'Nov_Revenue',
Sum(if(month = 'Dec' , revenue , null)) as 'Dec_Revenue'
from department group by id;