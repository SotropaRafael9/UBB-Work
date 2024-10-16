from django.shortcuts import render
from rest_framework.response import Response
from rest_framework.decorators import api_view
from rest_framework import status
from ..models import Nest
from ..serializers import NestSerializer

# Create your views operations here.

@api_view(['GET'])
def nest_list(request):
    nests = Nest.objects.all()
    serializer = NestSerializer(nests, many=True)
    return Response(serializer.data)

@api_view(['GET'])
def nest_detail(request, pk):
    try:
        nest = Nest.objects.get(id=pk)
    except Nest.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)
    
    serializer = NestSerializer(nest, many=False)
    
    return Response(serializer.data, status=status.HTTP_200_OK)

@api_view(['POST'])
def nest_create(request):
    serializer = NestSerializer(data=request.data)

    if serializer.is_valid():
        serializer.save()
        return Response(serializer.data, status=status.HTTP_201_CREATED)
    return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

@api_view(['PUT'])
def nest_update(request, pk):
    try:
        nest = Nest.objects.get(id=pk)
    except Nest.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)
    
    serializer = NestSerializer(instance=nest, data=request.data)
    
    if serializer.is_valid():
        serializer.save()
        return Response(serializer.data, status=status.HTTP_200_OK)
    return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

@api_view(['DELETE'])
def nest_delete(request, pk):
    try:
        nest = Nest.objects.get(id=pk)
    except Nest.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)
    
    nest.delete()
    
    return Response(status=status.HTTP_204_NO_CONTENT)
