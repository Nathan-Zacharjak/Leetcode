# Write your MySQL query statement below
-- SELECT Students.student_id, Students.student_name, Subjects.subject_name,
-- (COUNT()) AS attended_exams
-- FROM Students
--     INNER JOIN Examinations ON Students.student_id = Examinations.student_id
--     RIGHT JOIN Subjects on Examinations.subject_name = Subjects.subject_name

-- SELECT Examinations.student_id, Students.student_name, Examinations.subject_name,
--     COUNT(Examinations.subject_name)
--     AS attended_exams
--     FROM Examinations
--     INNER JOIN Students ON Students.student_id = Examinations.student_id
--     RIGHT JOIN Subjects ON Examinations.subject_name = Subjects.subject_name
--     GROUP BY Examinations.subject_name

SELECT s.student_id, s.student_name, sub.subject_name, COUNT(e.student_id) AS attended_exams FROM Students s
    CROSS JOIN Subjects sub
    LEFT JOIN Examinations e ON s.student_id = e.student_id AND sub.subject_name = e.subject_name
    GROUP BY s.student_id, s.student_name, sub.subject_name
    ORDER BY s.student_id, sub.subject_name
