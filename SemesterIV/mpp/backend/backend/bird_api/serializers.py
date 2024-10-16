from rest_framework import serializers
from .models import Bird
from .models import Nest
from django.contrib.auth.models import User

#Class Bird Serializer
#transform from model to json
class BirdSerializer(serializers.ModelSerializer):
    class Meta:
        model = Bird
        fields = '__all__'

class NestSerializer(serializers.ModelSerializer):
    class Meta:
        model = Nest
        fields = '__all__'

class UserSerializer(serializers.ModelSerializer):
    class Meta:
        model = User
        fields = ['username', 'password']