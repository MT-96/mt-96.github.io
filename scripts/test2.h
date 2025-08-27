if([myTestClass class] == [myInheritedClass class]){
   NSLog(@"I'm the inheritedClass);
} 
if([myTestClass class] == [mySuperClass class]){
   NSLog(@"I'm the superClass);
} 

Using - (BOOL)isKindOfClass:(Class)aClass in this case would result in TRUE both times because the inheritedClass is also a kind of the superClass.

objective c test