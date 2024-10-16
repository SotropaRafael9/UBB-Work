from django.urls import path,re_path
from backend.bird_api.views import birds, nests, user

# URL patterns for the bird API

urlpatterns = [
    path('birds/', birds.bird_list),
    path('birds_detail/<int:pk>/', birds.bird_detail),
    path('birds_create/', birds.bird_create, name="bird_create"),
    path('birds_update/<int:pk>/', birds.bird_update, name="bird_update"),
    path('birds_delete/<int:pk>/', birds.bird_delete, name="bird_delete"),
    path('birds_sort/', birds.bird_sort, name="bird_sort"),
    path('birds_filter/', birds.bird_filter, name="bird_filter"),
    path('birds_paginated/', birds.bird_paginated, name="bird_paginated"),
    path('birds_count/', birds.bird_count, name="bird_count"),
    path('birds_piechart/', birds.bird_piechart, name="bird_piechart"),
    path('nests/', nests.nest_list, name="nest_list"),
    path('nests_detail/<int:pk>/', nests.nest_detail, name="nest_detail"),
    path('nests_create/', nests.nest_create, name="nest_create"),
    path('nests_update/<int:pk>/', nests.nest_update, name="nest_update"),
    path('nests_delete/<int:pk>/', nests.nest_delete, name="nest_delete"),
 
    re_path('login/', user.login, name='login'),
    re_path('register/', user.signup, name='register'),
    re_path('test_token/', user.test_token, name='test_token'),

    path('users/', user.user_list, name='user_list'),
]