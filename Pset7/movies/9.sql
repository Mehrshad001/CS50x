select name
from people
where id in (select distinct stars.person_id from stars join movies on movies.id = stars.movie_id where year ="2004")
order by birth
