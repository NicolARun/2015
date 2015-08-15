-- Create the table children

CREATE TABLE children
(
    childno int(11) NOT NULL auto_increment,
    fname varchar(30),
    age int(11),
    PRIMARY KEY (childno)
);

-- Populate the table 'children'
INSERT INTO children(fname, age) VALUES ('Jenny', 21);
INSERT INTO children(fname, age) VALUES ('Andrew', 17);
INSERT INTO children(fname, age) VALUES ('Gavin', 8);
INSERT INTO children(fname, age) VALUES ('Duncan', 6);
INSERT INTO children(fname, age) VALUES ('Emma', 4);
INSERT INTO children(fname, age) VALUES ('Alex', 15);
INSERT INTO children(fname, age) VALUES ('Adrian', 9);
