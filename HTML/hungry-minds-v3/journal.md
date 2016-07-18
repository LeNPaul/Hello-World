---
layout: page
title: Journal
---
<div class="posts">
  {% for post in site.categories.journal limit:4 %}
  <div class="post">
    <h1 class="post-title">
      <a href="{{ site.baseurl }}{{ post.url }}">
        {{ post.title }}
      </a>
    </h1>

    <!--<span class="post-date">{{ post.date | date_to_string }} - <i class="fa fa-clock-o" aria-hidden="true"></i> {% include read-time.html %}</span>-->

    <p>{{ post.content | strip_html | truncate: 300 }} <a href="{{ post.url }}">Read more</a>
    <span class="post-date" style="margin:0px"><i class="fa fa-calendar" aria-hidden="true"></i> {{ post.date | date_to_string }} - <i class="fa fa-clock-o" aria-hidden="true"></i> {% include read-time.html %}</span>
    </p>

  </div>
  {% endfor %}
</div>

<h3>
  <a href="#">More Posts</a>
</h3>
