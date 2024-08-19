select count(title)
from movies
where id in(select movie_id from ratings where rating like "10.0")
