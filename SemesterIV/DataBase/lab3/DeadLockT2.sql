use port_management
GO

SET DEADLOCK_PRIORITY HIGH -- solution
BEGIN TRAN
UPDATE Client SET last_name='Popita' WHERE id = 12
WAITFOR DELAY '00:00:10'
UPDATE Product SET price=133 where id = 2
COMMIT TRAN