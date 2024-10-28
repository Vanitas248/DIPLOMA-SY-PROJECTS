create database mproject;
CREATE TABLE Users (user_id INT,username VARCHAR(50),email VARCHAR(100), password VARCHAR(255) );


INSERT INTO Users (user_id, username, email, password) 
VALUES 
(1, 'john_doe', 'john@example.com', 'password123'),
(2, 'jane_smith', 'jane@example.com', 'password456'),
(3, 'mike_johnson', 'mike@example.com', 'password789'),
(4, 'lucy_brown', 'lucy@example.com', 'password000'),
(5, 'sam_green', 'sam@example.com', 'password111'),
(6, 'emma_white', 'emma@example.com', 'password222'),
(7, 'chris_black', 'chris@example.com', 'password333'),
(8, 'sara_blue', 'sara@example.com', 'password444'),
(9, 'dave_silver', 'dave@example.com', 'password555'),
(10, 'mia_gold', 'mia@example.com', 'password666'),
(11, 'jake_lee', 'jake@example.com', 'password777'),
(12, 'nina_kim', 'nina@example.com', 'password888'),
(13, 'tony_stark', 'tony@example.com', 'password999'),
(14, 'bruce_wayne', 'bruce@example.com', 'passwordabc'),
(15, 'clark_kent', 'clark@example.com', 'passworddef');

CREATE TABLE Posts (post_id INT,user_id INT,content VARCHAR(255));

INSERT INTO Posts (post_id, user_id, content) 
VALUES 
(1, 1, 'Hello, this is John\'s first post!'),
(2, 2, 'Hi, I am Jane. Excited to post here!'),
(3, 3, 'Mike here. Just joined this platform!'),
(4, 4, 'Lucy checking in! Happy to be here.'),
(5, 5, 'Sam Green says hello!'),
(6, 6, 'Emma sharing my first thoughts.'),
(7, 7, 'Chris Black reporting for social media duty!'),
(8, 8, 'Sara Blue here, ready to connect!'),
(9, 9, 'Dave Silver saying hello!'),
(10, 10, 'Mia Gold sharing some good vibes!'),
(11, 11, 'Jake Lee posting my first message!'),
(12, 12, 'Nina Kim excited to explore this platform!'),
(13, 13, 'Tony Stark testing out my new social suit.'),
(14, 14, 'Bruce Wayne has something to share!'),
(15, 15, 'Clark Kent flying in with a quick post!');


SELECT * FROM Users;

SELECT * FROM Posts;
