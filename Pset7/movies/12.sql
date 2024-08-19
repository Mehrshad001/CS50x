select title from people
join stars on stars.person_id = people.id
join movies on stars.movie_id = movies.id
where name = "Bradley Cooper"
and movie_id in (select movie_id from people join stars on stars.person_id = people.id where name = "Jennifer Lawrence")
