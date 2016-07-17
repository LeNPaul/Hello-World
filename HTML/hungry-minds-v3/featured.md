---
layout: page
title: Featured
---

{% assign featured_posts = (site.posts|where:"featured","true") %}
{% for post in featured_posts limit:4 %}
<div class="related">
<ul class="related-posts">
<li>
  <h3>
  <a href="{{ site.baseurl }}{{ post.url }}">
    {{ post.title }}
    <small>{{ post.date | date_to_string }}</small>
  </a>
  </h3>
</li>
</ul>
</div>
{% endfor %}
