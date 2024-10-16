use port_management
GO

DROP TABLE IF EXISTS LogTable
CREATE TABLE LogTable(
	lid int identity primary key, 
	type_operation varchar(64),
	table_operation varchar(64),
	execution_date datetime
)
GO

CREATE OR ALTER FUNCTION ValidateString (@str VARCHAR(30)) RETURNS INT 
AS
BEGIN
	DECLARE @return INT
	SET @return=1
	IF (@str IS NULL OR LEN(@str) < 2 OR LEN(@str) > 64)
	BEGIN 
		SET @return = 0
	END
	RETURN @return
END
GO

CREATE OR ALTER FUNCTION ufValidateInt (@int int)
RETURNS INT
AS
BEGIN
	DECLARE @return INT
	SET @return = 1
	IF(@int < 0)
	BEGIN
		SET @return = 0
	END
	RETURN @return
END
GO

CREATE OR ALTER FUNCTION ufValidateFloat (@nr float)
RETURNS INT
AS
BEGIN
	DECLARE @return INT
	SET @return = 1
	IF(@nr < 0)
	BEGIN
		SET @return = 0
	END
	RETURN @return
END
GO

CREATE OR ALTER PROCEDURE AddShip(@id_ship int, @name varchar(64), @build_year int, @ship_type varchar(64)) AS 
	SET NOCOUNT ON
	IF (dbo.ValidateString(@id_ship) <> 1)
	BEGIN
		RAISERROR('Ship Name is invalid', 14,1)
	END
	IF (dbo.ufValidateFloat(@name) <> 1)
	BEGIN
		RAISERROR('Price can not be null',14,1)
	END
	IF (dbo.ufValidateInt(@build_year) <> 1)
	BEGIN
		RAISERROR('The build_year is invalid',14,1)
	END
	INSERT INTO Ship VALUES(@id_ship, @name,@build_year,@ship_type)
	INSERT INTO LogTable VALUES('add','ship',GETDATE())
GO

CREATE OR ALTER PROCEDURE AddBattleShip(@id_ship int,@name varchar(64),@wepons varchar(64), @speed float(3), @safty float(3))AS
	SET NOCOUNT ON
	IF (dbo.ufValidateInt(@id_ship) <> 1) OR EXISTS (SELECT * from Battle_ship B where B.id_ship = @id_ship)
	BEGIN
		RAISERROR('The id is not valid',14,1)
	END 
	IF (dbo.ValidateString(@name) <> 1)
	BEGIN
		RAISERROR('The name is invalid',14,1)
	END
	IF (dbo.ValidateString(@wepons) <> 1)
	BEGIN
		RAISERROR('The wepons is invalid',14,1)
	END
	INSERT INTO Battle_ship VALUES(@id_ship,@name,@wepons, @speed, @safty)
	INSERT INTO LogTable VALUES('add','battleShip',GETDATE())
GO

CREATE OR ALTER PROCEDURE AddCargoShip(@id_ship int,@name varchar(64),@weight float,@speed float, @safety float) AS
	SET NOCOUNT ON
	IF (dbo.ufValidateInt(@id_ship) <> 1)
	BEGIN
		RAISERROR('Id of the CargoShip is not valid',14,1)
	END
	IF (dbo.ValidateString(@name) <> 1)
	BEGIN
		RAISERROR('Name of the CargoShip is not valid',14,1)
	END
	IF (dbo.ufValidateFloat(@weight) <> 1)
	BEGIN
		RAISERROR('The weight text is not valid',14,1)
	END
	IF (dbo.ufValidateFloat(@speed) <> 1)
	BEGIN
		RAISERROR('The speed is not valid',14,1)
	END
	IF NOT EXISTS (SELECT * FROM Ship S WHERE @id_ship = S.id_ship)
	BEGIN 
		RAISERROR('The ship is not in the database',14,1)
	END
	IF NOT EXISTS (SELECT * FROM Battle_ship B WHERE @id_ship = B.id_ship)
	BEGIN 
		RAISERROR('The BattleShip is not in the database',14,1)
	END
	INSERT INTO Cargo_ship VALUES(@id_ship,@name ,@weight,@speed, @safety)
	INSERT INTO LogTable VALUES('add','cargoShip',GETDATE())
GO

CREATE OR ALTER PROCEDURE AddCommitScenario AS
	BEGIN TRAN 
	BEGIN TRY
		EXEC AddShip 1, 'Droage', 2022, 'BattleShip'
		EXEC AddBattleShip 1,'Bebe', 'Macelaru', 17,76
		EXEC AddCargoShip 1,'Verona', 12, 21.3,87
		COMMIT TRAN
		PRINT 'Transaction completed'
	END TRY
	BEGIN CATCH
		ROLLBACK TRAN
		PRINT 'Transaction aborted'
		PRINT ERROR_MESSAGE()
		RETURN
	END CATCH
GO

CREATE OR ALTER PROCEDURE AddRollbackScenario AS
	BEGIN TRAN 
	BEGIN TRY
		EXEC AddShip 1, 'Droage', 2022, 'BattleShip'
		EXEC AddBattleShip 1,'Bebe', 'Macelaru', -17,76 -- this will fail
		EXEC AddCargoShip 1,'Verona', 12, 21.3,87
		COMMIT TRAN
		PRINT 'Transaction completed'
	END TRY
	BEGIN CATCH
		ROLLBACK TRAN
		PRINT 'Transaction aborted'
		PRINT ERROR_MESSAGE()
		RETURN
	END CATCH
GO

EXEC AddCommitScenario
EXEC AddRollbackScenario

SELECT * from LogTable
delete from Ship 
SELECT * from Ship
SELECT * FROM Battle_ship
SELECT * FROM Cargo_ship

DELETE FROM Ship WHERE name LIKE 'Droage'
DELETE FROM Battle_ship where id_ship = 20
DELETE FROM Cargo_ship where weight LIKE 12