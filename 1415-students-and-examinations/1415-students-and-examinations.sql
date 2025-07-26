with cte as (
    select s.student_id, s.student_name, sub.subject_name from Students s cross join  Subjects sub order by student_id, subject_name 
)

select cte.* , count(e.subject_name) as attended_exams from  cte left join Examinations e on cte.student_id = e.student_id and cte.subject_name = e.subject_name group by cte.subject_name , cte.student_name order by cte.student_id , cte.subject_name; 

-- join Examinations e on s.student_id = e.student_id order by e.student_id , e.subject_name; 
