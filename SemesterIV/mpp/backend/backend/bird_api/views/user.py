from django.shortcuts import get_object_or_404
from rest_framework.response import Response
from rest_framework.decorators import api_view
from rest_framework.authtoken.models import Token   
from rest_framework import status
from ..serializers import UserSerializer
from rest_framework.authentication import SessionAuthentication, TokenAuthentication
from rest_framework.permissions import IsAuthenticated
from rest_framework.decorators import permission_classes, authentication_classes
from django.contrib.auth.models import User
# Create your views operations here.

@api_view(['POST'])
def login(request):
    if request.method == 'POST':
        user = get_object_or_404(User, username=request.data['username'])
        print("Login user", user)
        if not user.check_password(request.data['password']):
            return Response({'detail': "Not found"}, status=status.HTTP_404_NOT_FOUND)
        token, created = Token.objects.get_or_create(user=user)
        serielizer = UserSerializer(instance=user)
        return Response({'token': token.key, 'user': serielizer.data}, status=status.HTTP_200_OK)


@api_view(['POST'])
def signup(request):
    if request.method == 'POST':
        serializer = UserSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            user = User.objects.get(username=request.data['username'])
            user.set_password(request.data['password'])
            user.save()
            token = Token.objects.create(user=user)
            return Response({'token': token.key, 'user': serializer.data}, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

@api_view(['GET'])
@authentication_classes([SessionAuthentication, TokenAuthentication])
@permission_classes([IsAuthenticated])
def test_token(request):
    return Response({'detail': "You are authenticated"}, status=status.HTTP_200_OK)

@api_view(['GET'])
def user_list(request):
    
    users = User.objects.all()
   
    serializer = UserSerializer(users, many=True)
    return Response(serializer.data)