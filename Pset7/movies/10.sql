select name
from people
where id in (select distinct directors.person_id
from directors join movies on movies.id = directors.movie_id
where id in (select movie_id from ratings where rating >= "9.0"))
