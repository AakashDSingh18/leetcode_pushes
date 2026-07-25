SELECT e1.name as Employee
FROM Employee e1
INNER JOIN Employee e2
ON e1.managerId=e2.id
WHERE e2.salary<e1.salary;

-- Synced seamlessly with LeetHub Pro
-- Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
-- Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna