use Projects



-- Create the SemesterProject table
CREATE TABLE SemesterProject (
    project_id int PRIMARY KEY identity(1,1),
    name VARCHAR(255) NOT NULL
);

-- Create the ProjectTeam table
CREATE TABLE ProjectTeam (
    team_id int PRIMARY KEY identity(1,1),
    name VARCHAR(255) NOT NULL,
    project_id INT REFERENCES SemesterProject(project_id)
);

-- Create the StudentMember table
CREATE TABLE StudentMember (
    member_id int PRIMARY KEY identity(1,1),
    name VARCHAR(255) NOT NULL,
    role VARCHAR(50),
    team_id INT REFERENCES ProjectTeam(team_id)
);

-- Create the Task table
CREATE TABLE Task (
    task_id int PRIMARY KEY identity(1,1),
    description TEXT,
    member_id INT REFERENCES StudentMember(member_id)
);

-- Create the SoftwareTool table
CREATE TABLE SoftwareTool (
    tool_id int PRIMARY KEY identity(1,1),
    name VARCHAR(255) NOT NULL,
    description TEXT
);

-- Create the License table
CREATE TABLE License (
    license_id int PRIMARY KEY identity(1,1),
    tool_id INT REFERENCES SoftwareTool(tool_id),
    availability_days INT
);
