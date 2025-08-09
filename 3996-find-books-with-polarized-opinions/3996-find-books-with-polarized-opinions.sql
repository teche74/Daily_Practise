select b.* , (max(session_rating) - min(session_rating)) as rating_spread , 
ROUND(
        SUM(CASE WHEN rs.session_rating <= 2 OR rs.session_rating >= 4 THEN 1 ELSE 0 END) * 1.0 / COUNT(*),
        2
    ) AS polarization_score from books b join reading_sessions rs on b.book_id = rs.book_id 
    GROUP BY b.book_id, b.title, b.author, b.genre, b.pages
HAVING 
    COUNT(*) >= 5
    AND MIN(rs.session_rating) <= 2
    AND MAX(rs.session_rating) >= 4
    AND (SUM(CASE WHEN rs.session_rating <= 2 OR rs.session_rating >= 4 THEN 1 ELSE 0 END) * 1.0 / COUNT(*)) >= 0.6
ORDER BY polarization_score DESC, title DESC;